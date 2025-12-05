Public Class Derived
    Inherits Base

    Protected Overrides ReadOnly Property ProtectedOverridableProperty As String
        Get
            Return "* Derived protected overrided property"
        End Get
    End Property

    'Public Sub New()
    '    'Public and protected attributes or properties can be overridden using methods 
    '    _protectedAttributte = "* Derived protected attribute"
    '    PublicProperty = "* Derived public property"
    '    ProtectedProperty = "* Derived protected property"
    'End Sub

    Protected Overrides Sub PrintClassName()
        Console.WriteLine("Derived class:")
    End Sub

End Class