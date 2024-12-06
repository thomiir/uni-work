using seminar10.model;

namespace seminar10.factory;

public interface IFactory
{
    IContainer CreateContainer(Strategy strategy);
}