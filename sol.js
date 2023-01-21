var k=1; //声明一个计数器变量   
while(true)
{ //程序主体部分   
	var obj=doucument.getElementById("img");    
	if (k<2) 
	{
		k++;  
	}
	else 
	{
		k=1;   
	}   
	obj.src="images/"+k+".jpg"
	setTimeout(500); //每三秒钟刷新一次。   
}   