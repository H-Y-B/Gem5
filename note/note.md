


### power gating  

	ref link: https://aijishu.com/a/1060000000120919

### probe points
	
	探测点

### Event

	gem5中所有和时序相关的操作都是由event来驱动的，比如tick、trap、writeback等等。
	Event是event queue中的node，任何需要使用Event作为基类的子类需要重构虚函数Event中的process()以实现相应的event功能

	EventFuntionWrapper 
