namespace assignment6
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

        private void button1_Click(object sender, EventArgs e)
        {
            double annualRate = 0.05;
            double amount = double.Parse(textBox1.Text);
            int year = 5;

            while (year > 0)
            {
                amount = (amount * annualRate) + amount;
                year--;
            }
            label3.Text = "€ " + amount.ToString("0.00");
        }
    }
}