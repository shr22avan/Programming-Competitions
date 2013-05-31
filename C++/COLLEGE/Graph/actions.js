var c=document.getElementById("mycanvas");
var ctx=c.getContext("2d");
ctx.moveTo(0,550);
ctx.lineTo(1500,550);
ctx.stroke();
ctx.moveTo(50,600);
ctx.lineTo(50,0);
ctx.stroke();
ctx.font="30px Arial";
ctx.fillText("Data Index",500,580);
function fill(x,y,ct){
	ctx.fillStyle="#FF0000";
	ctx.fillRect((x+1)*10+50,540-(y+1)*10,10,10);
}
function empty(){
	ctx.fillStyle="#FFFFFF";
	ctx.fillRect(51,0,1500,549);
}
function plot(idx){
	console.log(idx);
	empty();
	for(var i=0;i<data[idx].length;i++){
		fill(i,data[idx][i],idx);
	}
}
function timeout(ctr,t){
	setTimeout(function(){plot(ctr)},t);
}
function doGraph(){
	for(var ctr=0;ctr<data.length;){
		var time=100*(ctr+1);
		timeout(ctr,time);
		ctr++;
	}
}
doGraph();
