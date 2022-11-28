let max_value, operand1 = 0;
let operand2 = 0;
const result = 0;
let flag = 0;
let sign = "+";
let input = "";
var element_config;
var element_range;
//#D3906C
function set_max_value(typing){
    max_value = parseInt(typing);
    switch (max_value){
        case 10:
            change_range_color_by_element_index(0);
            break;
        case 18:
            change_range_color_by_element_index(1);
            break;
        case 20:
            change_range_color_by_element_index(2);
            break;
        case 100:
            change_range_color_by_element_index(3);
            break;
    
    }
}
function change_range_color_by_element_index(index){
    if(typeof(element_range)!="undefined"){
        element_range.style.backgroundColor = "#EFEFEF";
    }
    element_range = document.getElementsByClassName('colorizing')[index];
    element_range.style.backgroundColor  = "#D3906C";
}
function change_operand_color_by_element_index(index){
    if(typeof(element_config)!="undefined"){
        element_config.style.backgroundColor = "#EFEFEF";
    }
    element_config = document.getElementsByClassName('operand_colorizing')[index];
    element_config.style.backgroundColor  = "#D3906C";
}
//10 Select addition or subtraction
function set_sign(x) {
    if (x == "+") {
        flag = 0;
        sign = "+";
        change_operand_color_by_element_index(0);
    }
    if (x == "-") {
        flag = 1;
        sign = "-";
        change_operand_color_by_element_index(1);
    }
    if (x == "*") {
        flag = 2;
        sign = "*";
        change_operand_color_by_element_index(2);
    }
    return true;
}

//16 Determine first operand
function f_operand() {
    operand1 = Math.floor(Math.random() * max_value);
    return parseInt(operand1);
}

//21 Determine second operand
function s_operand() {
    if (flag == 0) {
        operand2 = Math.floor(Math.random() * (max_value - operand1));
    } else {
        operand2 = Math.floor(Math.random() * operand1);
    }
    return parseInt(operand2);
}

//30 Check entered data
function input_sign(x) {
    if (x == 10) {
        if (flag == 0) {
            if (operand1 + operand2 == parseInt(input)) {
                window.document.test.r0.value = "Well done";
            } else {
                window.document.test.r0.value = "Think!";
                window.document.test.input = "";
                input = "";
            }
        }
        if (flag == 1) {
            if (operand1 - operand2 == parseInt(input)) {
                window.document.test.r0.value = "Well done";
            } else {
                window.document.test.r0.value = "Think!";
                window.document.test.input = "";
                input = "";
            }
        }
        if (flag == 2) {
            if (operand1 * operand2 == parseInt(input)) {
                window.document.test.r0.value = "Well done";
            } else {
                window.document.test.r0.value = "Think!";
                window.document.test.input = "";
                input = "";
            }
        }
        return true;
    }
    input += x;
    window.document.test.result.value = input;
    return true;
}

//60 Variant generation
function main_calc() {
    operand1 = f_operand();
    window.document.test.op1.value = operand1;
    operand2 = s_operand();
    window.document.test.op2.value = operand2;
    window.document.test.s_sign.value = sign;
    input = "";
    window.document.test.input = "";
    window.document.test.r0.value = " ???";
//70
    return true;
}