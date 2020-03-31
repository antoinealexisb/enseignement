
//question 3

function question3(){
	document.body.style.backgroundColor = "yellow";
}


document.onload = function () {
//quesiotn 4

document.getElementsByTagName('div')[0].addEventListener("mouseover", question4); //Déclenche la fonction question4 lors du survol.

function question4()
	{
	a = Math.floor(Math.random() * Math.floor(256));
	b = Math.floor(Math.random() * Math.floor(256));
	c = Math.floor(Math.random() * Math.floor(256));
	document.getElementsByTagName('div')[0].style.backgroundColor = "rgb(" + a + "," + b + "," + c + ")";
	//document.getElementsByTagName('div')[0].style.backgroundColor = "black";
	}
}
//question5
i=0;
function question5(){
	document.body.style.backgroundImage="url(imgs/"+i%4+".jpg)";
	i++;
}


