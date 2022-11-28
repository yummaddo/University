var imlocation = "images/";

function ImageArray(n) {
	this.length = n;
	for (var i = 1; i <= n; i++) {
    	this[i] = ' '
	}
}

image = new ImageArray(7);
image[0] = 'sunday.png';
image[1] = 'monday.png';
image[2] = 'tuesday.png';
image[3] = 'wednesday.png';
image[4] = 'thursday.png';
image[5] = 'friday.png';
image[6] = 'saturday.png';
var currentdate = new Date();
var imagenumber = currentdate.getDay();
document.write('<p class="image_position"><img src="' + imlocation + image[imagenumber] + '"></p>');