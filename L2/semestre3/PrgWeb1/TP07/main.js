function verif_pseudo(str){
	var regex_geo= new RegExp(/[^a-zA-Z0-9]/);
	if ((regex_geo.test(str))|| (str.length < 8) || (str.length > 25)){
		return false;
	}else{
		return true;
	}
}

	
function verif_email(str){
	var regex_add= new RegExp(/^[a-zA-Z0-9_\-.]+@[a-z]{2,}\.[a-z]{2,4}$/);
		if (regex_add.test(str)){
			return true;
		}else{
			return false;
		}
}

function verification(form){
	var test1 = verif_pseudo(form[0].value);
		if (!test1){
			form[0].style.backgroundColor="red";
		}		
		else {
			form[0].style.backgroundColor="green";
		}
			
	var test2 = verif_email(form[1].value);
		if (!test2){
			form[1].style.backgroundColor="red";
		}
		else{
			form[1].style.backgroundColor="green";
		}
	return (test1 && test2);
	}
	
window.onload=function(){
	var form=document.getElementById("formulaire");
	form.onsubmit= function(){
		var rlt =verification(form);
		if (rlt)
			alert("Compte Validé");
		return false;
	
	}
}