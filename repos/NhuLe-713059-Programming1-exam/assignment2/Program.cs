using System.Text;

namespace assignment2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter a word: ");
            string input = Console.ReadLine();
            //byte[] asciiBytes = Encoding.ASCII.GetBytes(input);
            //int i = 0;

            //foreach (char c in asciiBytes)
            //{
            //    Console.WriteLine($"{c}: {asciiBytes[i++]}");
            //}

            for (int i = 0; i < input.Length; i++)
            {
                Console.WriteLine($"{input[i]}: {(int)input[i]}");
            }
        }
    }
}