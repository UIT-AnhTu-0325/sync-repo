namespace Assignment5
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Random rnd = new Random();
            //int number1 = rnd.Next(101, 10000);
            //int number2 = rnd.Next(101, 10000);
            //int number3 = rnd.Next(101, 10000);
            //int number4 = rnd.Next(101, 10000);

            //int result = number1 + number2 + number3 + number4; 

            //Console.WriteLine(number1);
            //Console.WriteLine(number2);
            //Console.WriteLine(number3);
            //Console.WriteLine(number4);
            //Console.WriteLine(result);

            //option2
            Random rnd1 = new Random();
            int result2 = 0;
            for (int i = 0; i < 4; i++)
            {
                int number = rnd1.Next(101, 10000);
                result2 += number;
                Console.WriteLine(number);
            }
            Console.WriteLine(result2);
        }
    }
}