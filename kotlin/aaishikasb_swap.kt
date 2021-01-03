fun main(args: Array<String>) {
    // Enter Values
    var first = 1.20f
    var second = 2.45f

    println("Values before swap:")
    println("First number = $first")
    println("Second number = $second")
    val temporary = first
    first = second
    second = temporary

    println("Values after swap:")
    println("First number = $first")
    println("Second number = $second")
}