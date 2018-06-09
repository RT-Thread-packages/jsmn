# jsmn

## 1、介绍
jsmn是一个超轻巧，携带方便，单文件，适用于单片机中存储空间有限的环境，简单的可以作为ANSI-C标准的JSON解析器

### 1.1 目录结构

| 名称 | 说明 |
| ---- | ---- |
| inc  | 头文件目录 |
| src  | 源代码目录 |
| examples | 例程目录 |
| test | 测试代码目录 |

### 1.2 许可证

jsmn package 遵循 MIT 许可，详见 `LICENSE` 文件。

### 1.3 依赖

对 RT-Thread 无依赖，也可用于裸机。

## 2、如何打开 jsmn

使用 jsmn package 需要在 RT-Thread 的包管理器中选择它，具体路径如下：

```
RT-Thread online packages
    IoT - internet of things --->
        [*] jsmn: is a minimalistic JSON parser in C
```

然后让 RT-Thread 的包管理器自动更新，或者使用 `pkgs --update` 命令更新包到 BSP 中。

## 3、使用 jsmn
jsmn软件包例子代码，该代码位于：[/examples/example_jsmn.c](examples/example_jsmn.c)

jsmn软件包测试代码，该代码位于：[/test/tests.c](test/tests.c)


## 3.1 API

### 3.1 jsmn解析 
`int jsmn_parse(jsmn_parser *parser, const char *js, size_t len, jsmntok_t *tokens, unsigned int num_tokens);`

| 参数 | 描述 |
| ---- | ---- |
| parser  | json对象 |
| js  | json格式字符串 |
| len  | json格式字符串长度 |
| tokens  | 存放token的地址 |
| num_tokens  | token的数量 |
| 返回 | ---- |
| -1  | 没能提供足够的存储空间 |
| -2  | json字符串包含非法字符 |
| -3  | 该字符串不是一个完整的json数据包 |
| count  | 返回token的数量 |


### 3.2 jsmn初始化
`void jsmn_init(jsmn_parser *parser);`

| 参数 | 描述 |
| ---- | ---- |
| parser  | json对象 |
| return  | 无 |


### 3.3 例子测试
在msh/>输入 `jsmn_exam` 

```
msh />jsmn_exam
file: example_jsmn.c
description: this is an example.
verson: v0.1.0
date: 2018.6.9
msh />
```


## 4、注意事项

暂无

## 5、联系方式 & 感谢

* 维护：[never](https://github.com/neverxie)
* jsmn原作者主页：https://github.com/zserge/jsmn
