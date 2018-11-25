using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using KeyVault;
using Moq;

namespace SampleService.Tests
{
    [TestClass()]
    public class SampleRequestTests
    {
        [TestInitialize]
        public void TestInitialize()
        {
            //Example of mocking framework
            var mockKeyvaultManager = new Mock<IKeyVaultManager>();
            mockKeyvaultManager.Setup(kv => kv.GetSecret<string>(It.IsAny<string>())).Returns("TestValue");
        }

        [TestMethod()]
        public void GetExamplesTest()
        {
            throw new NotImplementedException();
        }
    }
}