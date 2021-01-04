fun main() {
    println(isLeapYear(2020)) // return true
    println(isLeapYear2(2021)) // return "2021 is not leap year"
}

//return boolean
fun isLeapYear(year: Int) = (year % 4 == 0 || year % 100 == 0 && year % 400 == 0)

//return string
fun isLeapYear2(year: Int) =
        if (year % 4 == 0 || year % 100 == 0 && year % 400 == 0)
            "$year is leap year"
        else
            "$year is not leap year"