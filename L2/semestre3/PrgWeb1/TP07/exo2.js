var initElement = function(){
	var b = document.getElementById("bouton");
	b.onclick = test;
}

var test = function(){
	var p = document.getElementById('res');
	var txt = "Total = ";
	var res = 16400;
	var list = parseInt(document.getElementById("liste").value);
	var o = 0;
	var i;
	for(i = 2; i < 6; i += 1){
		if (document.forms[0].elements[i].checked)
			o += parseInt(document.forms[0].elements[i].value);
		}
	res += parseInt(list + o);
	txt = txt + res +"€"
	p.textContent = txt;
}
window.onload = initElement;
