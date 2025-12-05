Module Program

    Sub Main()
        Dim base As New Base()
        Dim derived As New Derived()

        base.WriteInfo()
        derived.WriteInfo()
    End Sub

End Module