const { S3Client, GetObjectCommand, PutObjectCommand } = require('@aws-sdk/client-s3');
const { getSignedUrl } = require('@aws-sdk/s3-request-presigner');

const accessKey = "";
const secretKey = "";

const s3Client = new S3Client({
    region: "ap-south-1",
    credentials: {
        accessKeyId: accessKey,
        secretAccessKey: secretKey
    }
});

function generatePresignedUrlForGetFromS3(key) {
    const command = new GetObjectCommand({
        Bucket: "nodejs.ahmadimran.com",
        Key: key
    });

    return getSignedUrl(s3Client, command, {
        expiresIn: 60 * 60 // Set the expiration time to one hour
    });
}

function generatePresignedUrlForUploadToS3(fileName, contentType) {
    const command = new PutObjectCommand({
        Bucket: "nodejs.ahmadimran.com",
        Key: `uploads/${fileName}`,
        ContentType: contentType
    });
    return getSignedUrl(s3Client, command, {
        expiresIn: 60 * 60 // Set the expiration time to one hour
    });
}




// Example usage for generating presigned urls:

// generatePresignedUrlForGetFromS3('restarant.png').then(url => {
//     console.log('Presigned URL:', url);
// }).catch(err => {
//     console.error('Error generating presigned URL:', err);
// });

// generatePresignedUrlForUploadToS3(`image-${Date.now()}.png`, "image/png").then(url => {
//     console.log('Presigned URL:', url);
// }).catch(err => {
//     console.error('Error generating presigned URL:', err);
// });