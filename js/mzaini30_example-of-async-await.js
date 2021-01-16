// Node JS required
// 1. npm init -y
// 2. npm i node-fetch
fetch = require('node-fetch')
link = 'https://blogzen.js.org/beranda.json'
jalankan = async () => {
	x = await fetch(link)
	x = await x.json()
	console.log(x)
}
jalankan()
// 3. node example-of-async-await.js
