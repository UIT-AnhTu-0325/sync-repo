namespace assignment8
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int numberOfTshirt = int.Parse(textBox1.Text);
            int numberOfJean = int.Parse(textBox2.Text);

            DateTime curentDateTime = DateTime.Now;
            const double VAT = 21.00;
            const double priceTshirt = 30.00;
            const double priceJean = 100.00;

            double price = (numberOfTshirt * priceTshirt) + (numberOfJean * priceJean);
            double priceVAT = price * VAT / 100;
            double totalPrice = price + priceVAT;

            label8.Text = curentDateTime.ToString("G");
            label9.Text = "€" + " " + price.ToString("0.00");
            label10.Text = "€" + " " + priceVAT.ToString("0.00");
            label11.Text = "€" + " " + totalPrice.ToString("0.00");
        }
    }
}