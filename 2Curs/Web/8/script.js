//Task_1
function msgot()
{
    window.status = "Неправільно введені дані";
    alert(window.status);
}
function st(obj)
{
    let bal = [Number(obj.num1.value), Number(obj.num2.value), Number(obj.num3.value), Number(obj.num4.value), 
        Number(obj.num5.value), Number(obj.num6.value), Number(obj.num7.value), Number(obj.num8.value)];
    var sum = 0;
    for(let i = 0; i < 8; i++)
    {
        if(bal[i] < 60 || bal[i] > 100)
        {
            msgot();
            return;
        }
        sum = sum + bal[i];
    }
    let step = 0;
    let ser = sum / 8;
    if (ser > 94) step = 2900;
    else if (ser > 85) step = 2000;
    if (step == 0) alert("На жаль, вам стипендія не призначена");
    else alert("Вам призначена стипендія у розмірі "+ step +" грн.");
    obj.stip.value = "Ваш середній бал: " + ser;
}

function reg()
{
    let name = document.form2.regname.value;
    let group = document.form2.choice.value;
    if(name)
    {
        alert("ФІО: " + name + "\n" + "Група: " + group);
    }
    else msgot();
}

//Task_2

function big(name)
{
    document[name].width = 600;
    document[name].height = 600;
    document[name].style = "border: 8px solid #BC826B;";
}

function little(name)
{
    if(name == "p1"){
        document.p1.style = "";
    } else if(name == "p2"){
        document.p2.style = "";
    } else if(name == "p3"){
        document.p3.style = "";
    } else if(name == "p4"){
        document.p4.style = "";
    } else {
        document.p1.style = "";
        document.p2.style = "";
        document.p3.style = "";
        document.p4.style = "";
    }
    
}

let openedWindow;

function fullOpen()
{
    let num = document.form4.num.value;
    if (num == 1 || num == 2 || num == 3 || num == 4) openedWindow = window.open("img/p" + num + num + ".jpg");
    else msgot();
}