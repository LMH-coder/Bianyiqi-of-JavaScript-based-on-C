' Boxing is an implicit conversion of a value type to the type object or to any interface type implemented by this value type.
' Boxing a value type allocates an object instance on the heap and copies the value into the new object.
' https://learn.microsoft.com/en-us/dotnet/csharp/programming-guide/types/boxing-and-unboxing
' https://learn.microsoft.com/es-es/dotnet/visual-basic/programming-guide/language-features/data-types/how-to-convert-an-object-to-another-type

Module Program
    Dim o As Object

    Sub Main()
        Try
            ' The value assignment will return Nothing because the boxing.
            CastToNullableDecimal(DirectCast(o, Decimal?))
            PrintValue(o)

            ' The value assignment will return Nothing because the boxing.
            CastToNullableDecimal(CType(o, Decimal?))
            PrintValue(o)

            o = New Decimal?

            ' The value assignment will work.
            CastToNullableDecimal(o)
            PrintValue(o)
        Catch ex As Exception
            Console.WriteLine($"EXCEPTION: {ex.Message}")
        End Try
    End Sub

    Private Sub CastToNullableDecimal(ByRef d As Decimal?)
        If Not d.HasValue Then
            d = New Decimal?(0)
        Else
            d = New Decimal?(o)
        End If

        Console.WriteLine($"inner value of d: {d}")
    End Sub

    Private Sub PrintValue(o As Object)
        If o Is Nothing Then
            Console.WriteLine("final value of d: Nothing" & vbCrLf)
        Else
            Console.WriteLine($"final value of d: {o}" & vbCrLf)
        End If
    End Sub

End Module