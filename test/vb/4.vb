Module Program

    Sub Main()
        Dim dic As New Dictionary(Of Integer, String) From {
            {1, "One"},
            {2, "Two"},
            {3, "Three"}
        }

        'Iterate dictionary
        For Each kvp As KeyValuePair(Of Integer, String) In dic
            Console.WriteLine($"Key: {kvp.Key}{vbTab}{kvp.Value}")
        Next
    End Sub

End Module