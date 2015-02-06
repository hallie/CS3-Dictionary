function changeTextboxMode(mode){
    //Changes the value text within the textbox button when the
    //    radio value is changed (Search, Add, Delete)
    var val = document.getElementById("textbox_value");
    val.value = mode;
    //Changes the color of the button
    // Search = #0095cd
    // Add = #3edb30
    // Delete = #FF1A00
    if (mode === "search") { val.style.background = "#0095cd"; }
    else if (mode === "add") { val.style.background = "#3edb30"; }
    else { val.style.background = "#ff1a00"; }
    val.style.width = "56px";
}
