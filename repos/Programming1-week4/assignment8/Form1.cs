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
            int num = int.Parse(textBox1.Text);
            int sum1 = 0;
            int sum2 = 0;

            for (int i = 0; i < num; i++)
            {
                sum1 = sum1 + i + 1;
            }
            sum2 = num * (num + 1) / 2;

            label5.Text = sum1.ToString();
            label6.Text = sum2.ToString();
        }
    }
}