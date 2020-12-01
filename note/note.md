


### power gating  

	ref link: https://aijishu.com/a/1060000000120919

### probe points

	探测点

### Event

	gem5中所有和时序相关的操作都是由event来驱动的，比如tick、trap、writeback等等。
	Event是event queue中的node，任何需要使用Event作为基类的子类需要重构虚函数Event中的process()以实现相应的event功能
	
	EventFuntionWrapper 

### PMU(power management unit)



### AtomicSimpleCPU

* atomic是指访存模式，在这种模式下，所有的访存都是在请求发出后立即返回，也就是说没有模拟访存的时间、队列特性
* simple是指处理器顺序执行，无流水线

### MacroOp(宏操作)

[处理器结构--MicroOp &&MacroOp Fusion(融合)](https://cloud.tencent.com/developer/article/1358004)

> 从AMD K7和Intel  Core架构时代起，X86处理器中加入了AMD称为宏操作（MacroOP）/Intel称为微操作融合（Fused  uOP）的设计，这种设计可以将执行类uOP和载入/存储类uOP合并在一起组成一条MacroOP或Fused OP指令发射到 ICU (Instruction Cache Unit ,指令缓存单位)。
>
> from :https://www.cnbeta.com/articles/tech/100474.htm  or https://pc.watch.impress.co.jp/docs/column/kaigai/336298.html

### microcodeRom

	CISC有些指令过于复杂，如有一条指令就实现图像处理的，这样的指令直接用硬件实现比较困难，于是引出了微代码的概念。CISC中绝大部分指令是通过微代码控制硬件逻辑电路实现的。CISC中通过微代码间接实现的指令称为宏指令，相应微代码一般固化在ROM中。当然为了修正，优化等目的后来发布的在运行时调入内存（RAM）中的形式存在，如微软就曾经在ｗｉｎ７平台上为提高Intel处理器稳定性而写了一些宏指令，发布出来供大众下载。

### ref link：

[Cache访存并发度解析建模](http://www.doc88.com/p-2746116203962.html)

[VLIWDSP指令级精度模拟器的快速实现方法](https://www.doc88.com/p-9169449843731.html)