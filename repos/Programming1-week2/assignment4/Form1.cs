namespace assignment4
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            const double VAT = 21.00;
            string input = textBox1.Text;
            input = input.Trim();

            double price = double.Parse(input);
            double vatPrice = price * VAT / 100;
            double total = price + vatPrice;

            label3.Text = price.ToString("0.00");
            label4.Text = vatPrice.ToString("0.00");
            label6.Text = total.ToString("0.00");
        }
    }
}