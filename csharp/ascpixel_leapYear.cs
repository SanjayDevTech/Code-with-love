// C# program to determine if a year is a leap year or not.
// Optimized to have the least IL instructions.

using System;

static class Program
{
    /// <summary>
    /// Main entry-point method.
    /// </summary>
    public static void Main()
    {
        int year;

        Console.Write("Enter the year you want to check: ");
        year = int.Parse(Console.ReadLine());

        Console.Write("Year " + year + " is ");

        if (!((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
            Console.Write("not ");

        Console.WriteLine("a leap year.");
    }

    /*
     * Input: 2020
     * Output: Year 2020 is not a leap year.
     * 
     * Input: 1996
     * Output: Year 1996 is a leap year.
     */
}