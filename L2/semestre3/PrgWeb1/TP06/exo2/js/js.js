function change() {
    if (document.getElementById("select").value === "bleu") {
        document.styleSheets[0].disabled = true;
        document.styleSheets[1].disabled = true;
        document.styleSheets[2].disabled = false;
    }
    if (document.getElementById("select").value === "rouge"){
        document.styleSheets[0].disabled = true;
        document.styleSheets[1].disabled = false;
        document.styleSheets[2].disabled = true;
    }
    if (document.getElementById("select").value === "green") {
        document.styleSheets[0].disabled = false;
        document.styleSheets[1].disabled = true;
        document.styleSheets[2].disabled = true;
    }
}
