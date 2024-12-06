using seminar10.factory;
using seminar10.model;
using seminar10.decorator;

namespace seminar10;

public static class Start
{
    private static MessageTask[] CreateMessages()
    {
        var msg1 = new MessageTask("1", "feedback lab 2", "Te-ai descurcat bine", "teacher", "student", DateTime.Now);
        var msg2 = new MessageTask("2", "feedback lab 3", "Te-ai descurcat bine", "teacher", "student", DateTime.Now);
        var msg3 = new MessageTask("3", "feedback lab 4", "Te-ai descurcat bine", "teacher", "student", DateTime.Now);
        var msg4 = new MessageTask("4", "feedback lab 5", "Te-ai descurcat bine", "teacher", "student", DateTime.Now);
        var msg5 = new MessageTask("5", "feedback lab 6", "Te-ai descurcat bine", "teacher", "student", DateTime.Now);

        return [msg1, msg2, msg3, msg4, msg5];
    }
    
    public static void Main()
    {
        var messageTasks = CreateMessages();
        foreach (var messageTask in messageTasks)
            Console.WriteLine(messageTask);
        const Strategy strategy = Strategy.Lifo;
        var strategyTaskRunner = new StrategyTaskRunner(strategy);
        foreach (var message in messageTasks)
            strategyTaskRunner.AddTask(message);
        var printerTaskRunner = new PrinterTaskRunner(strategyTaskRunner);
        printerTaskRunner.ExecuteAll();
    }
}
    
