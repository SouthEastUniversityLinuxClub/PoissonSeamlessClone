# 一、问题描述

- 实现Poisson Image Editing算法的无缝融合应用(大型稀疏方程组求解)

# 二、算法描述

现在假设我们有图像g，如下图所示：

![](http://img.blog.csdn.net/20150525203216907?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvaGppbWNl/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center)

还有一张背景图片S：

![](http://img.blog.csdn.net/20150525204514091?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvaGppbWNl/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center)

现在我们希望把图片g融合粘贴到s中，且实现自然融合的效果：

![](http://img.blog.csdn.net/20150525204820724?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvaGppbWNl/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center)

## 1.计算图像g的梯度场

通过差分的方法，可以求得图像g的梯度场v：

![](http://img.blog.csdn.net/20150525205041364?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvaGppbWNl/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center)

OpenCV接口为：

```
computeGradientX(patch,patchGradientX);//计算ROI区域转换复制到destination一样大小的patch图片x方向梯度  
computeGradientY(patch,patchGradientY);//计算y方向梯度 
```

## 2.计算背景图片的梯度场

变量destination为背景图像。这样就得到了背景图片的梯度场(destinationGradientX,destinationGradientY)，如下图：

![](http://img.blog.csdn.net/20150526095429996?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvaGppbWNl/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center)

```
computeGradientX(destination,destinationGradientX);//计算背景图像的x方向梯度  
computeGradientY(destination,destinationGradientY);//计算背景图像y方向的梯度  
```

## 3.计算融合图像的梯度场

计算完了以后，我们就把图像g的梯度场覆盖到S的梯度场上，先对destinationGradientX、destinationGradientY做mask操作：

```
arrayProduct(destinationGradientX,binaryMaskFloatInverted, destinationGradientX);  
arrayProduct(destinationGradientY,binaryMaskFloatInverted, destinationGradientY);  
```

然后把图像g的梯度场覆盖到S的梯度场上：

```
Mat laplacianX = Mat(destination.size(),CV_32FC3);  
Mat laplacianY = Mat(destination.size(),CV_32FC3);  
//因为前面已经对destinationGradientX做了固定区域的mask，patchGradientX做了修改区域的mask  
laplacianX = destinationGradientX + patchGradientX;//求解整张图片新的梯度场  
laplacianY = destinationGradientY + patchGradientY;  
```

把背景图片的Ω区域的梯度场直接替换为g的梯度场v就可以了。

## 4.求解融合图像的散度

通过步骤3，我们可以得到每个像素点的梯度值，也就是待重建图像的梯度场，因此接着我们需要对梯度求偏导，从而获得散度。

```
computeLaplacianX(laplacianX,laplacianX);//求解梯度的散度 也就是拉普拉坐标  
computeLaplacianY(laplacianY,laplacianY);  
```

## 5.求解系数矩阵

第4步我们已经把散度计算完毕，前面的泊松重建方程，Ax=b，b便是散度，因此接着我们需要只要构建系数矩阵，还有约束方程就完成了。

![](http://img.blog.csdn.net/20150526101709180?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvaGppbWNl/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center)

如果一幅图像，除了边界像素点之外，比如上面3*3图像的边界像素点1、2、3、4、6、7、8、9，其它像素点的散度(上图中的像素5)已知。那么可以列出泊松方程：
$$
[V(2)+V(4)+V(6)+V(8)]-4*V(5)=div(5)
$$
然后如果一幅图像的边界像素点的像素值已知，那么就可以求解泊松方程了，假设约束点的值为u。以上面3*3的图像为例，最后系数矩阵A的构造为：

![](http://img.blog.csdn.net/20150526102823772?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvaGppbWNl/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center)

然后最后列出Ax=b的结果为：

![](http://img.blog.csdn.net/20150526103249415?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvaGppbWNl/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center)

这样分别求解三个通道的方程，我们就可以获得每个点的像素R,G,B值了。

# 三、结果



# 四、总结

