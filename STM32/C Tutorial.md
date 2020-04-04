# 学习 C和指针 总结

**空白和注释**
制表符`tab`用于缩进语句，更好的显示程序的结构。
合理简短的注释(comment)能够是代码更容易被阅读者理解，注释语法见下
~~~c
/*
**
**
**
*/
~~~
如果不想让一段代码从源文件真正意义上删除，不要在代码前末尾加上`/*,``*/`，如果代码本身含有注释，会出错。我们可以用预处理`#if`指令。
~~~c
#if 0
	statements
#endif
~~~

**预处理指令(preprocesseor directives)**
预处理指令是由预处理器解释的，预处理器读入源代码，修改，交给编译器。
~~~c
#include <stdio.h>
#include <stdlib.h>
#define		Max_COLS 20
#define 	MAX_iNPUT1000
~~~
在预处理器处理中，stdio.h(Standard I/O Library)和stdlib.h(自定应的头文件，里面定义程序需要的内容)两个头文件被搬到该源程序中用。`#define`宏定义变量

函数原型

**main函数**

```c
int main(void)/*int 表示函数返回一个整数值，void表示函数不接受任何参数*/
{
	int n_columns;/*声明整型标量*/
	int columns[MAX_COLS]/*声明整型数组*/
}
```
每个程序必须有一个main函数，它是程序执行的起点。
`所有传递给函数的参数都是按值传递的。`???

局部变量申明



如今软件开销最大之处并非在于编写，而在于维护

> `gets`函数从标准输入读取一行文本，并把它存储于 作为参数传递给它的数组中

`NUL`[^1]作为字符串终止符，本身不作为字符串一部分。字符串常量(string literal)就是源程序中被双引号括起来的一串，字符。比如：

>"Hello"
>在内存占6个字节，按顺序“H、e、l、l、o、Nul”

[^1]:NUL是ASCII字符集中的`\0`.NULL指一个其值为0的指针

常用printf格式代码

|格式|含义|
|--|--|
|%d\|o\|x|以十\|八\|六进制形式打印一个整数|
|%g|打印一个浮点值|
|%c|打印一个字符|
|%s|打印一个字符串|
|\n|换行|



**read_column_number函数**

~~~c
int read_column_numbers( int columns[], int max)
{
while( num < max && scanf( "%d", &columnns[nm] ) == 1
	&& columns[num] >=0 )
		num += 1;
		
	/*
	**确认已经读取得标号为偶数个，因为他们是以对的形式出现的。
	*/
	if( num % 2 !=0 ){
		puts( "Last column numner is not paired." );
		exit( EXIT_FALLURE );
	/*
	**丢弃改行中包含最后一个数字的那部分内容。
	*/
	while( (ch = getchar() ) != EOF && ch != `\n` )//赋值前面加上括号确保赋值运算先于比较运算。
		; 
}
~~~
这个声明和最早先出现在程序中的该函数原型的参数个数和类型以及函数的返回值完全匹配。在函数声明的数组参数 `int columns[]`中，未指定数组的长度

>`scanf函数`从标准输入读取字符，并根据读取格式字符串对他们进行转换----类似printf函数逆操作。
在所有的 变量参数 前面加上`&`, `%d` 读取一个整型值。字符从标准输入读取，然后数字被转换为一个整数，结果存储于指定的数组元素中。

>`puts函数`是`gets函数`的输出版本，它把指定的字符串写到标准输出并自动在末尾添加上一个换行符。put(参数)，printf(格式，参数)

puts函数是gets函数的输出版本

`getchar函数`从标准输入读取一个字符并且返回值，如果输入不存在内容就会返回EOF[^2]。返回值赋值给`ch`。然后与EOF比较，接着与换行符比较。因此只有当如输入未到达文件尾并且输入的字符非换行符时候，表达式才进行循环。
[^2]:End of File

return 语句就是函数向调用它的表达式返回一个值

**rearrange**

~~~c
/*
**处理输入行，将指定列的字符连接在一起，输出行以NUL结尾
*/
void
rearrange( char *output, char const *input,
			int n_columns, int const columns[] )
{
	int col;		/* columns数组的小标 */
	int output_col; /* 输出列计数器 */
	int len;		/* 输入行的长度 */
	len = strlen( input );
	output_col = 0;
	
	/*
	**处理每对 列标号。
	*/
	for( col = 0; col < n_columns; col += 2 ){
		int nchars = columns[col + 1] - columns[col] + 1;
		
		/*
		**如果输入行结束或者输出行数组已满，就结束任务。
		*/
		if( columns[col] >= len || 	
			output_col == MAX_INPUT - 1 )
				break;
		/*
		**如果输出行数据空间不够，只复制可以容纳的数据。
		*/
		if( output_col + nchars > MAX_INPUT -1 )
			nchars = MAX_INPUT - output_col -1;
		
		/*
		**复制相关的数据
		*/
		strncpy(output + output_col, input+ columns[col]，
				nchars );
		output_col += nchars;
	}
	output[output_col] ='\0'；
}
~~~



>`for语句`
>for(初始部分，测试条件部分，调整部分）
>	{
>	循环体
>	}
>
>-----------------
>等价于
>
>-----------
>初始部分
>while( 测试条件){
>	循环体
>	调整部分；
>	}


## 基本概念

### 环境
- translation environment
	源代码被转换为可执行的机器指令
- execution environment
	执行代码

![image-20200403182940701](D:\00_LUH\ET-INF\was_neues_lernen_Zusammenfassung\STM32\image-20200403182940701.png)

<center>图 2.1 编译过程</center>

Source code经过Compiler编译（编译过程也存在多个阶段，先预处理器处理比如#define,#include）然后产生.o的目标文件。这些个目标文件由Linker链接器捆绑，形成单一完整的可执行程序

一个c程序的源代码保存在一个或多个源文件中，但一个函数只能完整出现在同一个源文件中

标准定义了Trigraph三字母词

| ??(  | [    |      | ??<  | {    |
| :----: | :----: | ---- | :----: | :----: |
|  ??)    |]      |      |     ??>|}      |

但是当我们输入

~~~c
printf("Delete file (are you really sure??):");
~~~

输出结果就会出错，这里就需要用character escape字符转义

Identifier标识符，就是变量，函数，类型等的名字。C区分大小写

## 程序风格

合理使用空格，强调程序的结构。
1. 空行用于分割不同的逻辑代码段，按照功能分段。
2. if和相关语句的括号是是这些语句的一部分，而不是测试表达式一部分。所以，在括号和表达式之间留下一个空格使表达式更突出
3. 在绝大数操作符使用中，中间隔空格
4. 嵌套于其他语句的语句将Tab缩进，以显示他们层次。

<img src="D:\00_LUH\ET-INF\was_neues_lernen_Zusammenfassung\STM32\image-20200403191632375.png" alt="image-20200403191632375" style="zoom:50%;" />

第二个程序更容易发现while循环缺少右花括号。

## 函数
`main函数`
定义方式
~~~c
int main( void )
{
	...
	return 0;
}
~~~

int 指明函数返回类型，括号里包含传递给函数的信息。void表示没有给函数传递参数。C90标准允许如下，但是C99不允许
~~~c
int main()
{
	...
	return 0;
}
~~~

有时候还会看到
>void main()

这不是标准。
标准的意义在于：当你把程序从一个编译器搬移到另一个编译器，照常能运行。



`getchar()`
	头文件：#include <stdio.h>

​	函数getchar()用于从标准输入控制台读取字符，原型如下：

> int getchar(void);

【参数】该函数没有参数。

【返回值】函数的返回值为用户输入的第一个字符的ASCII码，若出错返回-1，且将用户输入的字符回显到屏幕。如果用户在按回车键之前输入了不只一个字符，其他字符会保留在键盘缓冲区中，等待后续getchar()调用读取。也就是说，后续的getchat()调用不会等待用户按键，而是直接读取缓冲区中的字符，直到缓冲区的字符读取完毕后，才等待用户按键。

【说明】getchar()非真正函数，而是getc(stdin)宏定义。





[c语言标准库](http://c.biancheng.net/cpp/u/biaozhunku/)