using System;
using System.Data.SqlClient;
using Microsoft.Extensions.Configuration;

class CalculatorProgram
{
    static void Main()
    {
        IConfiguration configuration = new ConfigurationBuilder()
            .AddJsonFile("appsettings.json", optional: true, reloadOnChange: true)
            .Build();
        string connectionString = configuration.GetConnectionString("MyDatabase");
        Console.WriteLine($"Connection String: {connectionString}");

        Console.WriteLine();
        Console.WriteLine();
        Console.WriteLine("\t=--------------------------=");
        Console.WriteLine("\tSimple Console Calculator C#\n");

        bool stillCalculating = true;

        while (stillCalculating)
        {
            double firstNum = GetPreviousResult(connectionString);
            double secondNum = 0;

            if (firstNum == 0)
            {
                Console.WriteLine("Type a number and press Enter: ");
                firstNum = Convert.ToDouble(Console.ReadLine());
            }
            else
            {
                Console.WriteLine($"Use previous result {firstNum} as the first number? (Y/N)");
                if (Console.ReadLine().ToUpper() == "N")
                {
                    Console.WriteLine("Type a new number and press Enter: ");
                    firstNum = Convert.ToDouble(Console.ReadLine());
                }
            }

            Console.WriteLine("Type a number and press Enter: ");
            secondNum = Convert.ToDouble(Console.ReadLine());

            Console.WriteLine("Enter which operation you would like to use:");
            Console.WriteLine("\t+");
            Console.WriteLine("\t-");
            Console.WriteLine("\t*");
            Console.WriteLine("\t/");
            Console.Write("Which operation would you like to use? ");

            string operation = Console.ReadLine();
            double result = 0;

            switch (operation)
            {
                case "+":
                    result = firstNum + secondNum;
                    break;
                case "-":
                    result = firstNum - secondNum;
                    break;
                case "*":
                    result = firstNum * secondNum;
                    break;
                case "/":
                    while (secondNum == 0)
                    {
                        Console.WriteLine("Enter a non-zero divisor: ");
                        secondNum = Convert.ToDouble(Console.ReadLine());
                    }
                    result = firstNum / secondNum;
                    break;
            }
            Console.WriteLine($"\nYour result is: {firstNum} {operation} {secondNum} = {result}");
            InsertCalculationIntoDatabase(firstNum, operation, secondNum, result, connectionString);

            Console.WriteLine("\nEnter Y to calculate again");
            Console.WriteLine("Enter N to quit");

            switch (Console.ReadLine())
            {
                case "Y":
                    Console.WriteLine();
                    break;

                case "N":
                    Console.WriteLine("\nClosing the calculator. Goodbye...\n");
                    DeleteCalculationsFromDB(connectionString);
                    stillCalculating = false;
                    break;
            }
        }
    }
    static void InsertCalculationIntoDatabase(double operand1, string operation, double operand2, double result, string connectionString)
    {
        string insertQuery = "INSERT INTO CalculatorResults (Operand1, Operation, Operand2, Result) VALUES (@Operand1, @Operation, @Operand2, @Result)";

        using (SqlConnection connection = new SqlConnection(connectionString))
        {
            connection.Open();

            using (SqlCommand cmd = new SqlCommand(insertQuery, connection))
            {
                cmd.Parameters.AddWithValue("@Operand1", operand1);
                cmd.Parameters.AddWithValue("@Operation", operation);
                cmd.Parameters.AddWithValue("@Operand2", operand2);
                cmd.Parameters.AddWithValue("@Result", result);

                cmd.ExecuteNonQuery();
            }
        }
    }
    static void DeleteCalculationsFromDB(string connectionString)
    {
        string deleteQuery = "DELETE FROM CalculatorResults";

        using (SqlConnection connection = new SqlConnection(connectionString))
        {
            connection.Open();

            using (SqlCommand cmd = new SqlCommand(deleteQuery, connection))
            {
                cmd.ExecuteNonQuery();
            }
        }
    }

    static double GetPreviousResult(string connectionString)
    {
        string selectQuery = "SELECT TOP 1 Result FROM CalculatorResults ORDER BY CalculationId DESC";

        using (SqlConnection connection = new SqlConnection(connectionString))
        {
            try
            {
                connection.Open();

                using (SqlCommand cmd = new SqlCommand(selectQuery, connection))
                {
                    var result = cmd.ExecuteScalar();
                    return (result == DBNull.Value) ? 0 : Convert.ToDouble(result);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
                return 0;
            }
        }
    }
}
