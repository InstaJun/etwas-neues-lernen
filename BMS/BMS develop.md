[TOC]
# 文献综述 - 大学生方程式级电池管理系统 #

作者：曾奕凯
来源：[文献综述（伪） - 大学生方程式级电池管理系统](https://zhuanlan.zhihu.com/p/66999119)

摘要：轻量化，
	设计流程：
		&rarr;对相关电池分析建模（基于赛事目标）
			&rarr;确定电池类型
				&rarr;电池组成组装配（基于电池箱相关的总布置方案）

## I.前言 ##

- 电池包占整车质量25%

- 欧美电动车自制BMS普遍 &harr;  国内电动方程式大多采用产品级别，比如[科列](##参考文献)
	* 相比产品级别，自制电路板，尺寸通常更小，有利于降低重心。对赛车动态性能产生影响， 因此更加基于整体的布置方案。同时，赛车整体的动态性能目标又会对电池选型产生影响[4],[5]。

## II.现状 ##

### 拓扑结构 ###
- 分布式拓扑结构 $\surd$
- 集中式拓扑结构
  区别: 是否将数个电芯集中到一起采样,还是逐个电芯采

  ![ig](https://pic1.zhimg.com/80/v2-3819b745d9e8c28ef50927ab12b379f8_1440w.jpg)
  
<center>图表 1 國立清華大學2019年分布式电池管理系统</center>

![img](https://pic1.zhimg.com/80/v2-2426896119ae51505a786f77488f5cb8_1440w.jpg)

<center>图 2 Formula student electric racing team from UAS Osnabrück, Germany, 2016</center>

图2 每个电芯在独立的电路板上进行采样,图1的采样模块将12块电芯电压引入到一块电路板进行采样.

![img](https://pic1.zhimg.com/80/v2-78fad140fdecdda0319db0df64beb320_1440w.jpg)

<center>图 3 双电池箱中的电池管理系统拓扑</center>

在[8]中提出了上述一种拓扑结构,在每个电池箱内布置一个主控(master)

![img](https://pic2.zhimg.com/80/v2-57402f77a886b5a8cb967e808bebe595_1440w.jpg)

<center>图4</center>

![两年BMS开发经验的关于BMS系统的思考和总结](https://pic2.zhimg.com/v2-2c4c33c4d1f0432227336d96bec2893a_1200x500.jpg)

<center>图4.5

### 电池模组 ###
电池模组的形状受制于电芯的选择，大致上可以区分为圆柱形的**电芯**和**软包电芯**。

![img](https://pic2.zhimg.com/80/v2-61f828eb62f96825be43627ed83bd22d_1440w.jpg)
<center>图表 5 University of Canterbury Motorsport 2016 电池模组</center>

图5 采用18650电芯。
[10]中模组由更小模块组成。
学生方程式赛车流行的成组方案--软包电芯，见图6所示，软包电池数值放置框架[11]。

### 极耳连接及采样 ###

<img src="https://pic1.zhimg.com/80/v2-1349bfda920a666d5faf2a73e4cb6df0_1440w.png" alt="img" style="zoom:150%;" />

<center>图表 6 Revolve NTNU 电池组</center>



![img](https://pic1.zhimg.com/80/v2-563149539c4b0229b622f24605c36440_1440w.jpg)
<center>图表 7 Ignition Racing Team electric 2017 电池极耳连接</center>

图表 7中的左右对比展示了电池极耳利用螺栓进行铆接，在连接电芯的同时也完成了对电压的采样。这种方式可以省略复杂的采样线缆，并且可以保证电池极耳不受到机械负载。然而重量略微高于直接采样激光焊接的方案。同时这种方式无极耳的圆柱形电池难以实现。

[14]中设计了一种用于圆柱形电池的采样板，利用电路板本身母线电流传导，如图8

![img](https://pic3.zhimg.com/80/v2-a0be3d8e67b141f727ba19d937490162_1440w.jpg)
<center>图表 8 UNIVERSITY OF WISCONSIN - MADISION 电池管理系统电路板设计</center>

另外一种不错的设计，挠性板采样[15]，如图9

![img](https://pic1.zhimg.com/80/v2-4d89ed45a7ba22c914ebe46d3e1d2a60_1440w.jpg)
<center>图表 9 FormUL 采样板及从控设计2018</center>

### 被动均衡 

- LTC6804 具有优秀的<u>被动均衡设计</u>

## III. 设计及制作流程

### 电池匹配及建模
北京理工大学大WANG 和 ZHANG 做了相关工作[4]。
基于模型的电池均衡策略设计[17]

![img](https://pic4.zhimg.com/80/v2-54200b7796c8d0402b1c8ca6912804e3_1440w.jpg)
<center>图10</center>

对于电池建模部分，采用了简易的RC模型
电池的模型还有很多种类[18]。基于这些参数，电池状态估计更加精确实现[19]

### 项目规划及测试

![img](https://pic1.zhimg.com/80/v2-50860dd644a011388d76c1381702e84c_1440w.jpg)
<center>图表 11 项目甘特图</center>

在形成成品车前，良好的测试环境搭建也是十分关键。

![img](https://pic1.zhimg.com/80/v2-9210433d1a901f7d855d7f7acf46f784_1440w.jpg)
<center>图12 电池箱测试环境</center>

### 后期文档记录
如本文中提到的各种优秀的文献资料一般，良好的设计流程记录是十分有益于设计的迭代。推荐阅读来自于University of Wisconsin-Madison的ESF表格[20]，需要注意的是其遵顼的规则并不一定仍然适用。

## IV.结论

本文介绍了许多优秀的大学生方程式电池管理相关的项目，其中有大量值得学习的技术经验以及项目管理方法。大学生方程式级别的电池管理系统已经出现了接近十年，十分期待国内的赛车队涌现出一批新的设计，提升车辆动态水平。









## 参考文献 ##
[1] 科列技术，深圳市南山区高新技术产业园，官网地址

[2] 同济电车队，上海，官网地址

[3] NTHU Racing - 清大賽車工廠，社交媒体账号

[4] Zhenpo Wang and Wenliang Zhang, "Battery system matching and design for a formula student electric racecar," 2014 IEEE Conference and Expo Transportation Electrification Asia-Pacific (ITEC Asia-Pacific), Beijing, 2014, pp. 1-6.

[5] V. Kalmakov, A. Andreev and G. Salimonenko, "Development of Formula Student Electric Car Battery Design Procedure", in International Conference on Industrial Engineering, 2016, pp. 1391 – 1395.

[6] Formulastudent.de, 2019. [Online]. Available: https://www.formulastudent.de/fileadmin/_migrated/content_uploads/FSG2011_Programme_Magazine_www.pdf. [Accessed: 25- May- 2019].

[7] "Ignition Racing Team electric on Instagram", Instagram, 2019. [Online]. Available: https://www.instagram.com/p/BH62pnIBzH-/?utm_source=ig_web_copy_link. [Accessed: 25- May- 2019].

[8] B. Santos, "Battery Management System applied to Projecto FST’s EV prototype", Instituto Superior Técnico, 2014.

[9] "Formula SAE: Electrical Systems", Canterbury.ac.nz, 2016. [Online]. Available: https://www.canterbury.ac.nz/media/documents/oexp-engineering/electrical-and-computer-engineering/FSAE_Rodin-Poster.pdf.

[10] T. Jutla, J. Clark and S. Chen, UCEM High Voltage Battery Design for Electric Vehicle. 2018.

[11] "Revolve NTNU - Unveiling 2019!&quot;, YouTube, 2019. [Online]. Available: https://www.youtube.com/watch?v=3OWv94cnGo8.

[12] Y. Frickx, "Formula Electric Belgium - Battery Management & Safety - Eurocircuits", Eurocircuits, 2018. [Online]. Available: https://www.eurocircuits.com/blog/formula-electric-belgium-own-electronic-control-unit-with-eurocircuits-pcbs-3-2/.

[13] ."Ignition Racing Team electric on Instagram", Instagram, 2017. [Online]. Available: https://www.instagram.com/p/BSqnW2ngM8Y/?utm_source=ig_web_copy_link.

[14] "WR-218e Battery — Wisconsin Racing", Wisconsin Racing, 2018. [Online]. Available: https://wisconsinracing.org/documents. [Accessed: 25- May- 2019].

[15] L. Asselin, "Battery Management System (Formula SAE Electric)", Asselin.Engineer, 2018. [Online]. Available: https://asselin.engineer/bms.

[16] A. Ha, Passive Balancing Battery Management System for Cal Poly Racing’s Formula SAE Electric Vehicle. San Luis Obispo, 2018.

[17] A. Girard, "Model-Based Design of an Electric Powertrain Vehicle; Focus on Physical Modeling of Lithium-ion Batteries", Master of Science, Faculty of the Virginia Polytechnic Institute and State University, 2016.

[18] 陈全世, 林成涛. 电动汽车用电池性能模型研究综述[J]. 汽车技术, 2005, 3：1-5.

[19] 戴海峰, 孙泽昌, 魏学哲. 利用双卡尔曼滤波算法估计电动汽车用锂离子动力电池的内部状态[J]. 机械工程学报, 2009, 45(6):95-101.

[20] Electrical System Form FSAE-E2018. 

