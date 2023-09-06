线段树
是用来存放给定区间（segment, or interval）内对应信息的一种数据结构。与树状数组（binary indexed tree）相似，线段树也用来处理数组相应的区间查询（range query）和元素更新（update）操作。与树状数组不同的是，线段树不止可以适用于区间求和的查询，也可以进行区间最大值，区间最小值（Range Minimum/Maximum Query problem）或者区间异或值的查询
对应于树状数组，线段树进行更新（update）的操作为O(logn)，进行区间查询（range query）的操作也为O(logn)。
————————————————
版权声明：本文为CSDN博主「耀凯考前突击大师」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/Yaokai_AssultMaster/article/details/79599809