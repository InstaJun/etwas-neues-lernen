# 电芯温度采样-NTC选型浅析

在电动汽车的bms设计当中,需要对绝大部分的电芯进行一个温度的测量。在KFZ当中运用最广泛的就是Heißleiter。

BMS的温度采样精度包括两部分，
- 电路本身的采样精度
- NTC的精度

温度采样电路示意图1

<img src="https://pic4.zhimg.com/80/v2-f6d846ee364d0a405bef42ef41c5ff7f_1440w.jpg" alt="img" style="zoom:50%;" />
<center>图1</center>

电路本身的采样精度，又包括了
- 上拉电阻精度、
- ADC精度、
- 参考电压源精度、
- 供电电源精度，
这个才是我们电路设计需要关注的问题。

![image-20200328114904313](D:\00_LUH\ET-INF\was_neues_lernen_Zusammenfassung\BMS\image-20200328114904313.png)
<center>图2 103JT-025</center>

可以从该超薄NTC参数表中，看出几个重要的参数。

## R25

零功率直流电阻值，R25就是在25$^\circ$C的本体标称阻值，见图3

![img](https://upload-images.jianshu.io/upload_images/18666985-44ced37bc1efc505.jpg?imageMogr2/auto-orient/strip|imageView2/2/w/400)

<center>图3</center>>

R25阻值常见的有10K、47K、100K，基本上见到的大部分是10K的，其他的比较少，现实中都是这样选取的。在-40$^\circ$C - 125$^\circ$C当中，不同R25的NTC，对应阻值范围也是不同，简单说就是，R25越大，它在其他温度点的阻值也就越大（参照下图4）。

<img src="D:\00_LUH\ET-INF\was_neues_lernen_Zusammenfassung\BMS\image-20200328123403063.png" alt="image-20200328123403063" style="zoom:50%;" />

<center>图4</center>

R25不是越大越好，一种可能的影响参照下图5，如果ADC内阻不大的话，阻值在低温时可能会与NTC的阻值接近，这样就会影响温度的采样精度了。

<img src="https://pic4.zhimg.com/80/v2-b77c8852b670d8bf4ff550e286d44d67_1440w.jpg" alt="img" style="zoom:50%;" />

<center>图6</center>

## B值（Materialkonstante）

B值是用来表示NTC对温度变化敏感度的物理量，即阻值的变化率。和材料有关，所以也叫材料常数

![img](https://upload-images.jianshu.io/upload_images/18666985-44ced37bc1efc505.jpg?imageMogr2/auto-orient/strip|imageView2/2/w/400)

<center>图7</center>

由图7也可以判断出，B值越大，该NTC随温度变化也越敏感。
B值的计算方法是拿两个温度点作为参考点，一般厂家是25℃和85℃，也标记为B25/85，它的计算公式如下(1-1)。
$$
B=\frac{ln_{R1}-ln_{R2}}{\frac{1}{T1}-\frac{1}{T2}}
\tag{1-1}
$$

在现实使用中，接触到的很多NTC的 B值是3435±1%，大家可以作为一个参考值去选型；另外 B值越大，R25也越大，二者之间很难灵活匹配。


## 总结

在电路设计时，会有一个期望的电阻范围，在这个范围内，温度点尽量要分散，两个温度点之间的阻值距离要大，这样我们可以用来分辨的准确度就会提高。所以可以根据R25和B值（即RT表），来锁定我们想要的NTC的型号。



## 参考资料

[电芯温度采样-NTC选型浅析](https://zhuanlan.zhihu.com/p/58015288?utm_source=wechat_session&utm_medium=social&utm_oi=881138743623426048)
其他资料
[NTC热敏电阻基础以及应用和选择](https://www.jianshu.com/p/8f9e46aa5559)
