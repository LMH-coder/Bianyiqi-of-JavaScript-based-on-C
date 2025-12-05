Public Class StringToDecimal

    Public Shared Sub Parse(value As Object)
        Dim dec As Decimal

        Try
            dec = Decimal.Parse(value)

            Console.WriteLine($"Converted {value} to {dec}")
        Catch ex As Exception
            Console.WriteLine($"Unable to convert: {value}")
        End Try
    End Sub

    Public Shared Sub TryParse(value As Object)
        Dim dec As Decimal

        If Decimal.TryParse(value, dec) Then
            Console.WriteLine($"Converted {value} to {dec}")
        Else
            Console.WriteLine($"Unable to convert: {value}")
        End If
    End Sub

End Class