namespace assignment7
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            int start = int.Parse(textBox1.Text);
            int end = int.Parse(textBox2.Text);
            double price = double.Parse(textBox3.Text);
            const double VAT = 21.00;

            double priceExclVAT = price * (end - start);
            double priceVAT = priceExclVAT * VAT / 100;
            double priceInclVAT = priceExclVAT + priceVAT;

            label7.Text = priceExclVAT.ToString("0.00");
            label8.Text = priceVAT.ToString("0.00");
            label9.Text = priceInclVAT.ToString("0.00");
        }

        private void label8_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            textBox1.Text = string.Empty;
            textBox2.Text = string.Empty;
            textBox3.Text = string.Empty;
        }
    }
}