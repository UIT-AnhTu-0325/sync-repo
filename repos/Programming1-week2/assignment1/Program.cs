namespace assignment1
{
    internal class Program
    {
        const double VAT = 21.00;
        static void Main(string[] args)
        {
            Console.Write("Enter a price: ");
            //string input = Console.ReadLine();

            double price = double.Parse(Console.ReadLine());
            double vatPrice = price * VAT / 100;
            double total = price + vatPrice;

            Console.WriteLine("price: " + price.ToString("0.00") + ", " + "VAT: "
                + vatPrice.ToString("0.00") + ", " + "total: " + total.ToString("0.00"));
        }
    }
}