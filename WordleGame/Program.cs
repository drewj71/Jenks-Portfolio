using System;
using System.IO;
using System.Collections.Generic;
using System.Runtime.CompilerServices;

class Program
{
    static void Main()
    {
        string filePath = @"C:\Users\drewj\OneDrive\Documents\VS Code Projects\CsharpProjects\WordleGame\acceptedWords.txt";
        WordleGame game = new WordleGame(filePath);
        game.PlayGame();
    }
}

class WordleGame
{
    private string secretWord;
    private string[] acceptedWords;
    private List<string> guessedWords = new List<string>();
    private int attemptsLeft = 6;
    private bool IsGameWon = false;
    private string[] LoadWordsFromFile(string filePath)
    {
        try
        {
            return File.ReadAllLines(filePath);
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error loading words from file: {ex.Message}");
            return new string[0];
        }
    }
    private void AssignSecretWord(string filePath)
    {
        acceptedWords = LoadWordsFromFile(filePath);
        if (acceptedWords.Length > 0)
        {
            Random random = new Random();
            secretWord = acceptedWords[random.Next(acceptedWords.Length)].ToUpper();
        }
        else Console.WriteLine("No words loaded from file. Check file path and content.");
    }
    public WordleGame(string filePath)
    {
        AssignSecretWord(filePath);
    }
    public bool IsGameLost()
    {
        return attemptsLeft == 0;
    }
    public void MakeGuess(string guess)
    {
        guess = guess.ToUpper();
        guessedWords.Add(guess);
        if (!secretWord.Contains(guess) && guess != null && guess.Length == 5)
        {
            attemptsLeft--;
        }
        else if (secretWord.Contains(guess))
        {
            IsGameWon = true;
        }
    }
    public void GetGuessFeedback(string guess)
    {
        // COLORED GUESS FEEDBACK USING ANSI ESCAPE CODES
        guess = guess.ToUpper();
        if (guess == secretWord)
        {
            Console.WriteLine($"\u001b[32m{guess}\u001b[0m"); // Green color
            Console.WriteLine("Congratulations, you have guessed the word!");
            return;
        }

        for (int i = 0; i < secretWord.Length; i++)
        {
            char secretChar = secretWord[i];
            char guessChar = (i < guess.Length) ? guess[i] : ' ';

            if (secretChar == guessChar)
            {
                Console.Write("\u001b[32m"); // Green color
            }
            else if (secretWord.Contains(guessChar.ToString()))
            {
                Console.Write("\u001b[33m"); // Yellow color
            }
            else
            {
                Console.Write("\u001b[0m"); // Reset color to default
            }

            Console.Write(guessChar);
        }

        Console.WriteLine(); // Move to the next line after printing the feedback
        Console.Write("\u001b[0m"); // Reset color to default
    }
    public void PlayGame()
    {
        do
        {
            Console.WriteLine($"Attempts left: {attemptsLeft}");
            Console.Write("Enter a 5-letter word: ");
            string userGuess = Console.ReadLine();

            if (userGuess != null && userGuess.Length == 5 && acceptedWords.Contains(userGuess))
            {
                MakeGuess(userGuess);
                GetGuessFeedback(userGuess);
            }
            else
            {
                Console.WriteLine("Invalid input. Please enter a valid 5-letter word.");
            }
        } while ((IsGameLost() || IsGameWon) == false);

        if (IsGameLost())
        {
            Console.WriteLine($"Sorry, you've run out of attempts. The correct word was: {secretWord}");
        }
    }
}