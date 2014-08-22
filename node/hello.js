var http = require('http');
http.createServer(function(request,response){
	response.writeHead(200);
	response.write("Hello World !\n");
	setTimeout(function() {
		response.write("BYE BYE");
		response.end();
	},5000);
}).listen(8080);
console.log("Listening to port 8080");