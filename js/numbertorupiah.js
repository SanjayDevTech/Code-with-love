const formatter = new Intl.NumberFormat('id-ID', {
  style: 'currency',
  currency: 'IDR', // "Kode Mata uang"
  minimumFractionDigits: 2 // "Desimal"
})

formatter.format(6000) // "Rp. 6,000.00"
formatter.format(50000) // "Rp. 50,000.00"
