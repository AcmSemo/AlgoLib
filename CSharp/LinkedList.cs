class LL<T>
{
    public T Data { get; set; }
    public LL<T> previous;
    public LL(T d, LL<T> prev = null)
    {
        Data = d;
        previous = prev;
    }
    public void addToList(T d)
    {
        previous = new LL<T>(Data, previous);
        Data = d;
    }
}