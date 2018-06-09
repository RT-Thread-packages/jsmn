/*
 * File      : example_jsmn.c
 * This file is the example code of jsmn package.
 * COPYRIGHT (C) 2006 - 2018, RT-Thread Development Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-06-09     never        the first version
 */

#include <rtthread.h>
#include <finsh.h>
#include <string.h>
#include "jsmn.h"

const char *JSON_STRING =
    "{\"file\":\"example_jsmn.c\", \
      \"description\":\"this is an example.\",\
      \"verson\":v0.1.0,\
      \"date\":2018.6.9}";

static int fetch_key(const char *JSON_STRING, jsmntok_t *t, const char *str)
{   
    int length;
    length = strlen(str);
    if ((t->type == JSMN_STRING) && (length == (t->end - t->start)))
    {   
        return strncmp(JSON_STRING + t->start, str, length);
    }
    else
    {
        return -1;
    }
}

int jsmn_exam(void)
{
    int i;
    int res;
    jsmn_parser p;
    jsmntok_t t[128] = {0};

    jsmn_init(&p);
    res = jsmn_parse(&p, JSON_STRING, strlen(JSON_STRING), t, sizeof(t) / sizeof(t[0]));
    if (res < 0)
    {
        rt_kprintf("Failed to parse JSON: %d\n", res);
        return -1;
    }

    if (res < 1 || t[0].type != JSMN_OBJECT)
    {
        rt_kprintf("Object expected\n");
        return -1;
    }

    for (i = 1; i < res; i++)
    {
        if (fetch_key(JSON_STRING, &t[i], "file") == 0)
        {
            rt_kprintf("file: %.*s\n", t[i+1].end - t[i+1].start, JSON_STRING + t[i+1].start);
            i++;
        }
        else if (fetch_key(JSON_STRING, &t[i], "description") == 0)
        {
            rt_kprintf("description: %.*s\n", t[i+1].end - t[i+1].start, JSON_STRING + t[i+1].start);
            i++;
        }
        else if (fetch_key(JSON_STRING, &t[i], "verson") == 0)
        {
            rt_kprintf("verson: %.*s\n", t[i+1].end - t[i+1].start, JSON_STRING + t[i+1].start);
            i++;
        }
        else if (fetch_key(JSON_STRING, &t[i], "date") == 0)
        {
            rt_kprintf("date: %.*s\n", t[i+1].end - t[i+1].start, JSON_STRING + t[i+1].start);
            i++;
        }
        else
        {
            rt_kprintf("un: %.*s\n", t[i].end - t[i].start, JSON_STRING + t[i].start);
        }
    }

    return 0;
}

MSH_CMD_EXPORT(jsmn_exam, jsmn example);
