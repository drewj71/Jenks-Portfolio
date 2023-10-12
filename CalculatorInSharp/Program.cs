// See https://aka.ms/new-console-template for more information

//double a = 4;
//double b = 10;
//double c = a + b;

//Console.WriteLine(c);
//Console.ReadKey();


bool stillCalculating = true;

while (stillCalculating)
{

    double firstNum = 0;
    double secondNum = 0;

    Console.WriteLine("\t=--------------------------=");
    Console.WriteLine("\tSimple Console Calculator C#\n");

    Console.WriteLine("Type a number and press Enter: ");
    firstNum = Convert.ToDouble(Console.ReadLine());

    Console.WriteLine("Type a number and press Enter: ");
    secondNum = Convert.ToDouble(Console.ReadLine());

    Console.WriteLine("Enter a letter for which operation you would like:");
    Console.WriteLine("\tA - Add");
    Console.WriteLine("\tS - Subtract");
    Console.WriteLine("\tM - Multiply");
    Console.WriteLine("\tD - Divide");
    Console.Write("Which operation would you like to use? ");

    switch (Console.ReadLine())
    {
        case "A":
            Console.WriteLine($"\nYour result is: {firstNum} + {secondNum} = " + (firstNum + secondNum));
            break;
        case "S":
            Console.WriteLine($"\nYour result is: {firstNum} - {secondNum} = " + (firstNum - secondNum));
            break;

        case "M":
            Console.WriteLine($"\nYour result is: {firstNum} * {secondNum} = " + (firstNum * secondNum));
            break;

        case "D":
            while (secondNum == 0)
            {
                Console.WriteLine("Enter a non-zero divisor: ");
                secondNum = Convert.ToDouble(Console.ReadLine());
            }
            Console.WriteLine($"\nYour result is: {firstNum} / {secondNum} = " + (firstNum / secondNum));
            break;
    }
    Console.WriteLine("\nEnter Y to calculate again");
    Console.WriteLine("Enter N to quit");

    switch (Console.ReadLine())
    {
        case "Y":
            Console.WriteLine("\nRestarting the calculator...\n");
            break;

        case "N":
            Console.WriteLine("\nClosing the calculator. Goodbye...\n");
            stillCalculating = false;
            break;
    }
}