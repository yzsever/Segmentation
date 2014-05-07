Segmentation
============
gcc -g segmentation.c -o test
gdb test
r
此时可以看到程序中的错误

1 堆内存访问越界，并且没有释放（fun1）
2 使用未初始化的内存（main）
3 内存读写越界 （fun2）
4 已释放的内存继续使用（fun3）
5 内存泄漏（badleak）

patch -p0 segmentation.c < seg.patch

然后就可以正常运行了
