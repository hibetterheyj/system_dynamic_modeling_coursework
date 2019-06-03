The model of the complex and mixed-domain dynamic systems can be simulated on the mostly used computer softwares offering built-in mathematical and graphical capabilities such as Matlab/Simulink, Modelec, Acsyde and Matrix/SystemBuild. This section describes the procedure followed when transposing the BG models to the block diagram (BD), this method was found to be user friendly and allows use of the familiar computer software (Matlab/Simulink) in simulating the BG models.  

Some elements for the BG transposition to block diagram are proposed. The BG junctions are represented by the summing BD junctions, whilst the constitutive laws of elements are transcribed by classic blocks with gain, integrators or derivative blocks (in case of derivative causality) [10]. The following terms will be used in the 3-port junction elements: 

复杂和混合域动态系统的模型可以在最常用的计算机软件上进行模拟，这些软件提供内置的数学和图形功能，如Matlab / Simulink，Modelec，Acsyde和Matrix / SystemBuild。 本节描述了将键合图模型转换为框图时所遵循的步骤，并使用Matlab / Simulink来模拟键合图模型。

---

3.4   State-space differential equations extraction 
After a system BG model has been expressed in integral causality form, it can hence be algorithmically transformed into a system of state space differential equations ready for simulation. This procedure is equivalent to generating block diagrams in a control-engineering framework and obtaining the transfer function [12]. The order of the differential equations depends on the number of storage elements (system dynamics) in the BG model with integral causality. 

Causality being the significant feature of Bond graph modelling, allows determination of the state variables and the number of equations that must be derived prior to deriving the single equation.  
The extraction of state-space mathematical representation will be clearly shown in the proceeding chapter. The matrix forms of the MPW and EPPW models will be given. 

状态空间微分方程提取

在以积分因果关系形式表示系统键合图模型之后，因此可以将其在算法上转换成准备用于仿真的状态空间微分方程系统。 此过程相当于在控制工程框架中生成框图并获得传递函数。 微分方程的阶数取决于具有积分因果关系的键合图模型中的状态元件的数量。

其中，因果关系是键合图建模的重要特征，允许确定状态变量和在推导单个方程之前必须导出的方程的数量。
状态空间数学表示的提取在前面的章节中清楚地显示出来。 将给出手推轮椅主体和电驱动模块的矩阵形式。

i.	Analysis of the system dynamics in order to identify the BG elements constituting the model of the system and pointing out the energy translation existing between the elements of the multi-disciplinary systems taking into account the position at which the power source is applied.
ii.	Identifying the references of common power variables (effort and flow) at different multiport junction elements with respect to BG construction rules described in [8].
iii.	Introduction of the integral causalled BG model and conversion to BD to enable simulation on Matlab Simulink.
iv.	Extraction of the state space differential equations and expression in matrix form is to be given as additional information (which could be used to study some control characteristics of the systems like stability, observability and controllability).

（1）分析系统动力学以识别构成系统模型的键合图元素，并指出考虑到应用电源的位置的多学科系统的元件之间存在的能量转换。

（2） 根据键合图构造规则，识别不同多端口连接元件处的公共功率变量（势和流）的参考，从而在Matlab Simulink上进行仿真。

（3）提取状态空间微分方程和矩阵形式的表达式作为附加信息（可用于研究系统的一些控制特性，如稳定性，可观测性和可控性）。

#### Manual Propelled Wheelchair (MPW) system 

手动轮椅系统是运输行动不便的人最常用的移动椅，包括两个方向自由前轮，称为“脚轮”和两个后轮，如下图箭头所示。 通过在连接到后轮的手轮缘上施加切向力来实现手动扭矩推进



As stated in chapter one, the motivation of this work derives from attempts to employ few portable mechatronic drive modules which can be coupled when necessary to a large scale of MPW systems with the aims of improving propulsion efficiency. The proposed engagement of such a module (to be modelized and simulated) on MPW is as illustrated in figure 4-10.  This yields good advantage to the system since the weight of the module is imposed on the module itself, thus prevents deformation of the structure.  

如第一章所述，这项工作的动机源于尝试使用少量便携式机电一体化驱动模块，这些模块可以在必要时与大规模的手推轮椅系统耦合，目的是提高推进效率。在手推轮椅系统上使用这种模块这为系统带来了良好的优势，因为模块的重量施加在模块本身上，从而减小结构变形带来的影响。

### 公式推导

$k_1$ 代表后轮半径。而 $k_2, k_3$ 代表两轮转弯时关于速度顺心的曲率半径。

- 后轮与地面运动状态分析


$$
\begin{equation}
\dot{p}_{2}
=
e_2
=
e_1
-
e_3
-
e_4
=
\tau_L
-
e_3
-
e_4
\end{equation}
$$

$$
\begin{equation}
e_3
=
f_3 \cdot R_{gL}
=
f_2 \cdot R_{gL}
=
\frac{p_{2}}{J_{wL}} R_{g L}
\end{equation}
$$

$$
\begin{equation}
e_4 = e_5 + e_8
=
e_6 + e_9 \cdot k_1
= 
\frac{q_{6}}{C_{wL}}
+
\frac{q_{11}}{C_{wcL}} k_{1}
\end{equation}
$$

由上式即可导出：

$$
\begin{equation}
\dot{p}_{2}
=
\tau_{L}
-
\frac{p_{2}}{J_{wL}} R_{g L}
-
\frac{q_{11}}{C_{wcL}} k_{1}
-
\frac{q_{6}}{C_{wL}}
\end{equation}
$$

- 后轮轮辐结构相关状态变量

$$
\begin{equation}
\dot{q}_{6}
=
f_6
=
f_5 - f_7
\end{equation}
$$

$$
f_5
=
f_4
=
f_2
=
\frac{p_{2}}{J_{w L}}
$$

$$
f_7
=
\frac{e_{7}}{R_{w L}}
=
\frac{e_{6}}{R_{w L}}
=
\frac{q_{6}}{C_{wL} R_{w L}}
$$

由上式即可导出：

$$
\begin{equation}
\dot{q}_{6}
=
\frac{p_{2}}{J_{w L}}-\frac{q_{6}}{C_{wL} R_{w L}}
\end{equation}
$$

- 后轮与整体解耦分析

$$
\begin{equation}
\dot{q}_{11}
=
f_{11}
=
f_9 - f_{10} - f_{12} - f_{13}
\end{equation}
$$

$$
\begin{equation}
f_{9}
=
f_{8} \cdot k_1
=
f_{4} \cdot k_1
=
f_{2} \cdot k_1
=
\frac{p_{2}}{J_{w L}} k_{1}
\end{equation}
$$

$$
\begin{equation}
f_{10}
=
\frac{e_{10}}{R_{wc L}}
=
\frac{e_{11}}{R_{wc L}}
=
\frac{q_{11}}{C_{wc L} R_{wc L}}
\end{equation}
$$

$$
\begin{equation}
f_{12}
=
\frac{f_{16}}{k_{2}} 
=
\frac{f_{17}}{k_{2}} 
=
\frac{p_{17}}{J_{t} k_{2}}
\end{equation}
$$

$$
\begin{equation}
f_{13}
=
f_{14}
=
\frac{p_{14}}{M_{t}}
\end{equation}
$$

由上式即可导出：

$$
\begin{equation}
\dot{q}_{11}
=
\frac{p_{2}}{J_{w L}} k_{1}
-
\frac{q_{11}}{C_{wc L} R_{wc L}}
-
\frac{p_{17}}{J_{t} k_{2}}
-
\frac{p_{14}}{M_{t}}
\end{equation}
$$

- 质心处状态分析（质量）

$$
\begin{equation}
\dot{p}_{14}
=
e_{14}
=
e_{13}
+
e_{15}
\end{equation}
$$

$$
\begin{equation}
e_{13}
=
e_{11}
=
\frac{q_{11}}{C_{wc L}}
\end{equation}
$$

$$
\begin{equation}
e_{15}
=
e_{20}
=
\frac{q_{20}}{C_{wc R}}
\end{equation}
$$

由上式即可导出：

$$
\begin{equation}
\dot{p}_{14}
=
\frac{q_{11}}{C_{wc L}}
+
\frac{q_{20}}{C_{wc R}}
\end{equation}
$$

- 质心处状态分析（转动惯量）

$$
\begin{equation}
\dot{p}_{17}
=
e_{17}
=
e_{16}
+
e_{18}
\end{equation}
$$

$$
\begin{equation}
e_{16}
=
\frac{e_{12}}{k_2}
=
\frac{e_{11}}{k_2}
=
\frac{q_{11}}{C_{w L} k_{3}}
\end{equation}
$$

$$
\begin{equation}
e_{18}
=
\frac{e_{19}}{k_3}
=
\frac{e_{20}}{k_3}
=
\frac{q_{20}}{C_{wc R}}
\end{equation}
$$

由上式即可导出：

$$
\begin{equation}
\dot{p}_{17}
=
\frac{q_{11}}{C_{w L} k_{3}}
+
\frac{q_{20}}{k_{2} C_{w R}}
\end{equation}
$$

- 右轮部分部分情况，根据对称即可导出：

$$
\begin{equation}
\dot{q}_{20}
=
\frac{p_{29}}{J_{w R}} k_{1}
-
\frac{p_{14}}{M_{t}}
-
\frac{p_{17}}{J_{t} k_{3}}
-
\frac{q_{20}}{R_{wc R} C_{wc R} }
\end{equation}
$$

$$
\begin{equation}
\dot{q}_{25}=\frac{p_{29}}{J_{w_{-} R}}-\frac{q_{25}}{R_{w_{-} R} C_{w_{-}} R}
\end{equation}
$$

$$
\begin{equation}
\dot{p}_{29}
=
\tau_{R}-\frac{p_{29}}{J_{w R}} R_{g R}
-
\frac{q_{20}}{C_{wc R}} k_{1}
-
\frac{q_{25}}{C_{w R}}
\end{equation}
$$

下列公式显示了MPW的状态空间表示，其中$ x_1$，$u_1$和$y_1$分别是系统状态，输入和输出。
$$
\begin{equation}
\dot{x}_1 =[\mathbf{A}_1] x_1+[\mathbf{B}_1] u_1
\end{equation}
$$

具体表示成：

$$
\begin{equation}
\begin{aligned}
\left[ 
\begin{array}
{l}{e_{2}} \\ {f_{6}} \\ {f_{11}} \\ {e_{14}} \\ {e_{17}} \\ {f_{20}} \\ {f_{25}} \\ {e_{25}}
\end{array}
\right]
=
\left[ 
\begin{array}
{c}{\dot{p}_{2}} \\ {\dot{q}_{6}} \\ {\dot{q}_{11}} \\ {\dot{p}_{14}} \\ {\dot{p}_{17}} \\ {\dot{q}_{20}} \\ {\dot{q}_{25}} \\ {\dot{p}_{29}}
\end{array}
\right]
=
&
\left[ 
\begin{array}
{cccccccc}{- \frac{R_{gL}}{J_{w L}}} & - \frac{1}{C_{wL}} & - \frac{k_1}{C_{w L}} & 0 & 0 & 0 & 0 & 0 \\ 
\frac{1}{J_{w L}} & - \frac{1}{R_{wL} C_{wL}} & 0 & 0 & 0 & 0 & 0 & 0 \\ 
\frac{k_{1}}{J_{W_L}}  & 0 & - \frac{1}{R_{wc L} C_{wc L}} & - \frac{1}{M_{t}} & - \frac{1}{k_{2} J_{t}} & 0 & 0 & 0  \\ 
0 & 0 & \frac{1}{C_{wc L}} & 0 & 0 & \frac{1}{C_{wc R}}  & 0 & 0   \\ 
0 & 0 & \frac{1}{k_{3} C_{wc L}} & 0 & 0 & \frac{1}{k_{2} C_{wc R}}  & 0 & 0  \\ 
0 & 0 & 0 & - \frac{1}{M_{t}} & - \frac{1}{k_{2} J_{t}} & - \frac{1}{R_{wc R} C_{wc R}} & 0 & \frac{k_{1}}{J_{W_R}} \\ 
0 & 0 & 0 & 0 & 0 & 0 & - \frac{1}{R_{w R}  C_{w R}} & \frac{1}{J_{w R}}  \\ 
0 & 0 & 0 & 0 & 0 & - \frac{k_{1}}{C_{wc R}} & - \frac{1}{C_{w R}} &  - \frac{R_{g R}}{J_{wR}} 
\end{array}
\right]
\left[
\begin{array}{c}
{p_{2}} \\ {q_{6}} \\ {q_{11}} \\ {p_{14}} \\ {p_{17}} \\ {q_{20}} \\ {q_{25}} \\ {q_{29}}
\end{array}
\right]
\\
&+
\left[ 
\begin{array}{ll}
{1} & {0} \\ {0} & {0} \\ {0} & {0} \\ {0} & {0} \\ {0} & {0} \\ {0} & {0} \\ {0} & {0} \\ {0} & {1}
\end{array}
\right]
\left[ \begin{array}{l}
{\tau_{L}} \\ {\tau_{R}}
\end{array}\right]
\end{aligned}
\end{equation}
$$

$$
\begin{equation}
y_1 =[\mathbf{C}_1] x_1
\end{equation}
$$

具体表示成：

$$
\begin{equation}
\left[
\begin{array}{c}{\omega_{L}} \\ {\omega_{R}} \\ {V_{C G}} \\ {\theta_{C G}}
\end{array}
\right]
=
\left[
\begin{array}{c}{f_{2}} \\ {f_{29}} \\ {f_{14}} \\ {f_{17}}\end{array}
\right]
=
\left[ \begin{array}{cccc}
{\frac{1}{J_{w L}}} & {0} & {0} & {0} \\ {0} & {\frac{1}{J_{w R}}} & {0} & {0} \\ {0} & {0} & {\frac{1}{M_{t}}} & {0} \\ {0} & {0} & {0} & {\frac{1}{J_{t}}}
\end{array}\right] 
\left[ \begin{array}{c}
{p_{2}} \\ {p_{29}} \\ {p_{17}} \\ {p_{17}}
\end{array}\right]
\end{equation}
$$

