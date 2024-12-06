namespace seminar10.decorator;

public class DelayTaskRunner(ITaskRunner taskRunner) : AbstractTaskRunner(taskRunner)
{
    public override void ExecuteOneTask()
    {
        try
        {
            Thread.Sleep(3000);
            base.ExecuteOneTask();
        }
        catch (Exception ex)
        {
            Console.WriteLine(ex.Message);
        }
    }
}