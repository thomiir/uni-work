using System.Globalization;

namespace seminar10.decorator;

public class PrinterTaskRunner(ITaskRunner taskRunner) : AbstractTaskRunner(taskRunner)
{
    private static readonly DateTimeFormatInfo DateTimeFormat = DateTimeFormatInfo.InvariantInfo;

    public override void ExecuteOneTask()
    {
        base.ExecuteOneTask();
        Console.WriteLine("Task executed at: " + DateTime.Now.ToString(DateTimeFormat));
    }
}