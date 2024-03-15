namespace assignment1
{
    internal class Program
    {
        const float VAT = 21;
        static void Main(string[] args)
        {
            CalcPrice();
        }

        static void CalcPrice()
        {
            Console.Write("Enter a price: ");
            string input = Console.ReadLine();

            float price = float.Parse(input);
            float vatPrice = price * VAT / 100;
            float total = price + vatPrice;

            Console.WriteLine("price: " + price.ToString("0.00") + ", " + "VAT: "
                + vatPrice.ToString("0.00") + ", " + "total: " + total.ToString("0.00"));
        }
    }
}