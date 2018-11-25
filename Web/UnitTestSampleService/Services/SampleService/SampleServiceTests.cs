using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using Moq;
using KeyVault;

namespace SampleService.Tests
{
    [TestClass()]
    public class SampleServiceTests
    {
        Mock<IKeyVaultManager> mockKeyvaultManager;

        [TestInitialize]
        public void TestInitialize()
        {
            //Example of mocking framework
            mockKeyvaultManager = new Mock<IKeyVaultManager>();
            mockKeyvaultManager.Setup(kv => kv.GetSecret<string>(It.IsAny<string>())).Returns("TestValue");
        }

        [TestMethod()]
        public void AddTest()
        {
            mockKeyvaultManager.VerifyAll();
            throw new NotImplementedException();
        }

        [TestMethod()]
        public void GetTest()
        {
            throw new NotImplementedException();
        }

        [TestMethod()]
        public void GetTest1()
        {
            throw new NotImplementedException();
        }

        [TestMethod()]
        public void UpdateTest()
        {
            throw new NotImplementedException();
        }

        [TestMethod()]
        public void DeleteTest()
        {
            throw new NotImplementedException();
        }
    }
}