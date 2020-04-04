# 电池包配置

![image-20200325175741692](D:\00_LUH\ET-INF\was_neues_lernen_Zusammenfassung\BMS\image-20200325175741692.png)
<center>图1</center>

## 电芯选择
Mingda Lithium Cobalt Oxide pounch cells 软包电芯的参数见图1。
**最大连续放电电流**以及**最大的电压**两个关键因素决定了最大输出功率 P~out~。值得一提的是，在电芯的Specification参数中的，电流单位为[C]，表示的充放电速率。当电芯总容量1000mAh，1C表示以1000mA，1小时充放电完毕。

## Zelle dimensienieren 
**required energy, discharge current, number of cells, etc.**

需要有足够的能量确保Endurance event完成
根据paper所给的如下公式来计算供给电机的能量。

$$
P_m=\frac{1}{\eta}(\frac{mgf}{3600}u + \frac{C_dA}{76140}u^3 + \frac{mgi}{3600}+\frac{\delta mu}{3600}\frac{du}{dt}) \tag{1}
$$

根据Endurance event功率时间曲线，可以由积分得到总消耗能量
$$
\int{P_m}\,{\rm d}t
\tag{2}
$$

同时考虑到电能的转换效率
$$
E_{final}=\frac{W}{\eta_{mc}\eta_q\eta_{dts}}
\tag {3}
$$

控制电机操作电压从250V 到300V ，电芯标称电压3.7V。那么串联级的电芯数为
$$
N_S=\frac{U_r}{U_C}=\frac{250V}{3.7V}=67.57
$$

换一种算法
$$
N_S=\frac{U_r}{U_C}=\frac{300V}{4.0V}=75
$$

在选择电芯数量时候，需要结合考虑电池包的Dimensionieren，Conainer Design，Managemer of the battery。这里选用72节串联电芯。
$$
U_r =3.7 \times 72V =266.4V
$$

为了能让电机达到最大输出功率85kW，最大电流不应小于
$$
I_mmax=\frac{P_mmax}{U_r}=\frac{85 000W}{266.4V}=319.070A
$$
并联电芯数量
$$
N_P=\frac{I_mmax}{15C}=\frac{319.070A}{15\times8.3A}=2.563
$$
在这里$N_P$选择3
电池包的规格*72S3P*


## 电池箱设计

由选择的电芯设计电池箱，需要考虑到电池包的冷却，整体车架的外形（这点在车体前期规划的时候就需要同时结合考虑，设计相互之间是制约关系），本paper设计的电池箱所用的材料聚碳酸酯板[^1]。见图1

![image-20200327192444057](D:\00_LUH\ET-INF\was_neues_lernen_Zusammenfassung\BMS\image-20200327192444057.png) 
<center>图1</center>



[^1]:polycarbonate sheet,抗冲击，重量轻较高拉伸强度、弯曲强度，耐热，耐寒，透光89%，撞击强度是钢化玻璃的2-20倍



为了能让电芯稳定的固定在电池先内，该paper设计了电芯框架(battery frame)，见图2

![image-20200327192939204](D:\00_LUH\ET-INF\was_neues_lernen_Zusammenfassung\BMS\image-20200327192939204.png)
<center>图2</center>

从图1中我们还能看出，电池箱内设计的由3个风扇，通过电池组的供电，使得风扇运转，从而让带走箱内的热量。用来扇热的措施除了3个风扇之外还在每个电芯框架中心设置了有导热丝

