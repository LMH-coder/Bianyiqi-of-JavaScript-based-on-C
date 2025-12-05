Public Class Join

    Public Shared Sub JoinLists()
        Dim lst As New List(Of String) From {"a", "b", "c"}
        Dim emptyList As List(Of String) = New List(Of String)

        ' Framework 3.5
        ' String.Join(" ", lst.Cast(Of String))

        ' Framework >=4
        Console.WriteLine($"Joined list as String: { String.Join(",", lst)}")
        ' Result: a, b, c.
        Console.WriteLine()

        ' Join an empty list will return empty string
        Console.WriteLine($"Joined emtyList: { String.Join(",", emptyList)}")

        ' Try to join a Nothing list will result in an exception
    End Sub

End Class