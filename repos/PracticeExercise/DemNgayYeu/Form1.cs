namespace DemNgayYeu
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            DateTime startDate = new DateTime(2023, 7, 4);
            DateTime now = DateTime.Now;
            int[] array = new int[] { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

            int sumDay = 0;
            int s1 = array[startDate.Month] - startDate.Day + 1;
            sumDay += s1;

            if (startDate.Year == now.Year)
            {
                for (int i = startDate.Month + 1; i < now.Month; i++)
                {
                    sumDay += array[i];
                }
            }
            else
            {

            }
            sumDay += now.Day;

            label2.Text = "Như";
            label3.Text = "Tú";
            label6.Text = sumDay.ToString();
            label9.Text = startDate.ToString("d");
        }

        private void button1_Click(object sender, EventArgs e)
        {
            
        }
    }
}