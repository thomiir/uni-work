using seminar10.model;

namespace seminar10.factory;

public class TaskContainerFactory : IFactory
{
    public IContainer CreateContainer(Strategy strategy)
    {
        if (strategy == Strategy.Fifo)
            return new QueueContainer();
        return new StackContainer();
    }
}